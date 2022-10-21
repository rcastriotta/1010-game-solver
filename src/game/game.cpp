#include "game.hpp"

#include <algorithm>
#include <vector>
#include <iostream>
#include <thread>

#include "app/constants.hpp"
#include "ai/move.hpp"
#include "ai/ai.hpp"
#include "ai/scoring_function.hpp"
#include "raw/raw_board.hpp"
#include <nlohmann/json.hpp>

constexpr bool T = true, F = false;
namespace game {

void Game::generateNewPieces() {
    for (int i = 0; i < app::PIECE_COUNT; ++i) {
        const Piece& piece = allPiecesGameProbability[distribution(randomNumberGenerator)];
        //const Piece& piece = allPiecesGameProbability[distribution(randomNumberGenerator)];
        //auto chosenPiece = std::find_if(begin(allPiecesGameProbability), end(allPiecesGameProbability), [=](const Piece& e) {return e.id == piece.id;});
        pieces[i] = piece.id;}
}

void Game::generateNewPiecesIfNeeded() {
    if (std::all_of(pieces.begin(), pieces.end(), [](piece_id_t id) { return id == pieceNone.id; })) {
        generateNewPieces();
    }
}


void Game::calculateHasLost() {
    hasLost = !std::any_of(pieces.begin(), pieces.end(), [this](piece_id_t id) {
        return id != pieceNone.id && board.fitsPieceAnywhere(id);
    });
}


Game::Game(const ai::Ai& ai)
        : ai{ai},
        distribution{0, allPiecesGameProbability.size() - 1} {
    reset();
}


const Board& Game::getBoard() const {
    return board;
}

const std::array<piece_id_t, app::PIECE_COUNT>& Game::getPieces() const {
    return pieces;
}

int Game::getScore() const {
    return score;
}

bool Game::getHasLost() const {
    return hasLost;
}

bool Game::getUseAi() const {
    return useAi;
}


void Game::toggleUseAi() {
    useAi = !useAi;
}

void Game::placePieceReleasedAt(int movedPiece, int i, int j) {
    if (board.fitsPieceAt(j, i, pieces[movedPiece])) {
        score += board.placePieceAt(j, i, pieces[movedPiece]);

        // remove piece that was used
        pieces[movedPiece] = pieceNone.id;

        generateNewPiecesIfNeeded();
        calculateHasLost();
    }
}

void Game::reset() {
    score = 0;
    board = Board();

    auto seed = std::random_device{}();
    randomNumberGenerator = std::mt19937{seed},
   // std::cout << "Starting empty game with seed: " << seed << "\n";

    generateNewPieces();
    calculateHasLost();
}

void Game::printMoves(std::string gridState, std::string pieces)  {
    auto gridParsed = nlohmann::json::parse(gridState);
    std::vector<piece_id_t> piecesParsed = nlohmann::json::parse(pieces);

    // set grid state
    for (int a = 0; a < 10; ++a) {
        for (int j = 0; j < 10; j++) {
            if (gridParsed[j][a] == 1) board.placePieceAt(j, a, 19);
        }
    }
    auto moves = ai.bruteForce(board.getRawData(), piecesParsed);
    for (auto move : moves) {
        if (!board.fitsPieceAt(move.i, move.j, move.id)) {
            std::cout << "The ai provided an invalid move: " << move.i << " " << move.j << " " << (int)move.id << "\n";
            useAi = false;
            return;
        }

        score += board.placePieceAt(move.i, move.j, move.id);

        int usedIndex = std::find(pieces.begin(), pieces.end(), move.id) - pieces.begin();
        pieces[usedIndex] = pieceNone.id;
    }

    nlohmann::json result;
    int index = 0;
    for (auto move : moves) {
        std::string s = std::to_string(move.id);
        result["coords"].push_back({s, move.i + 1, move.j + 1, index});
        index++;
    }
    result["grid"] = board.getData();
    std::cout << result.dump();
    exit(0);
}

void Game::tick() {
    if (useAi) {
        std::vector<piece_id_t> availablePieces;
        for (auto piece : pieces) {
            if (piece != pieceNone.id) {
                availablePieces.push_back(piece);
            }
        }

        auto moves = ai.bruteForce(board.getRawData(), availablePieces);

       //std::this_thread::sleep_for(std::chrono::milliseconds(10000));

        for (auto move : moves) {
            if (!board.fitsPieceAt(move.i, move.j, move.id)) {
                std::cout << "The ai provided an invalid move: " << move.i << " " << move.j << " " << (int)move.id << "\n";
                useAi = false;
                return;
            }

            score += board.placePieceAt(move.i, move.j, move.id);

            int usedIndex = std::find(pieces.begin(), pieces.end(), move.id) - pieces.begin();
            pieces[usedIndex] = pieceNone.id;
        }
        if (moves.empty()) {
            hasLost = true; // The ai provided no moves, so it has lost
            return;
        }

        generateNewPiecesIfNeeded();
        calculateHasLost();
    }
}

} // namespace game