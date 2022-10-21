#pragma once

#include <cstdint>
#include <array>

#include "game/board.hpp"

namespace raw {

// all are 50 bits long
constexpr raw_board_t pieceMask[] {
	0b0, // pieceNone
	0b1000000000'1000000000'1000000000'1000000000'1000000000, // pieceLong5Vertical
	0b1000000000'1000000000'1000000000'1000000000'0000000000, // pieceLong4Vertical
	0b1000000000'1000000000'1000000000'0000000000'0000000000, // pieceLong3Vertical
	0b1000000000'1000000000'0000000000'0000000000'0000000000, // pieceLong2Vertical
	0b1111100000'0000000000'0000000000'0000000000'0000000000, // pieceLong5Horizontal
	0b1111000000'0000000000'0000000000'0000000000'0000000000, // pieceLong4Horizontal
	0b1110000000'0000000000'0000000000'0000000000'0000000000, // pieceLong3Horizontal
	0b1100000000'0000000000'0000000000'0000000000'0000000000, // pieceLong2Horizontal
	0b1110000000'1110000000'1110000000'0000000000'0000000000, // pieceSquare3x3
	0b1100000000'1100000000'0000000000'0000000000'0000000000, // pieceSquare2x2
	0b1110000000'1000000000'1000000000'0000000000'0000000000, // pieceAngle3x3TL
	0b1110000000'0010000000'0010000000'0000000000'0000000000, // pieceAngle3x3TR
	0b0010000000'0010000000'1110000000'0000000000'0000000000, // pieceAngle3x3BR
	0b1000000000'1000000000'1110000000'0000000000'0000000000, // pieceAngle3x3BL
	0b1100000000'1000000000'0000000000'0000000000'0000000000, // pieceAngle2x2TL
	0b1100000000'0100000000'0000000000'0000000000'0000000000, // pieceAngle2x2TR
	0b0100000000'1100000000'0000000000'0000000000'0000000000, // pieceAngle2x2BR
	0b1000000000'1100000000'0000000000'0000000000'0000000000, // pieceAngle2x2BL
	0b1000000000'0000000000'0000000000'0000000000'0000000000, // pieceSingle
    0b0100000000'1110000000'0000000000'0000000000'0000000000, // newOne
    0b1110000000'0100000000'0000000000'0000000000'0000000000, // newTwo
    0b1000000000'1100000000'1000000000'0000000000'0000000000, // newThree
    0b0100000000'1100000000'0100000000'0000000000'0000000000, // newFour
    0b1110000000'1010000000'1110000000'0000000000'0000000000, // newFive 3x3 with hole in middle    0b1110000000'1010000000'1110000000'0000000000'0000000000, // newFive 3x3 with hole in middle
    0b1100000000'0110000000'0000000000'0000000000'0000000000, // newSix
    0b0110000000'1100000000'0000000000'0000000000'0000000000, // newSeven
    0b0100000000'1100000000'1000000000'0000000000'0000000000, // newEight
    0b1000000000'1100000000'0100000000'0000000000'0000000000, // newNine
    0b1110000000'1000000000'0000000000'0000000000'0000000000, // newTen
    0b1110000000'0010000000'0000000000'0000000000'0000000000, // newEleven
    0b1000000000'1000000000'1100000000'0000000000'0000000000, // newTwelve
    0b0100000000'0100000000'1100000000'0000000000'0000000000, // newThirteen
    0b1000000000'1110000000'0000000000'0000000000'0000000000, // newFourteen
    0b0010000000'1110000000'0000000000'0000000000'0000000000, // newFifteen
    };

constexpr board_index_t pieceWidth[] {
	0, // pieceNone
	1, // pieceLong5Vertical
	1, // pieceLong4Vertical
	1, // pieceLong3Vertical
	1, // pieceLong2Vertical
	5, // pieceLong5Horizontal
	4, // pieceLong4Horizontal
	3, // pieceLong3Horizontal
	2, // pieceLong2Horizontal
	3, // pieceSquare3x3
	2, // pieceSquare2x2
	3, // pieceAngle3x3TL
	3, // pieceAngle3x3TR
	3, // pieceAngle3x3BR
	3, // pieceAngle3x3BL
	2, // pieceAngle2x2TL
	2, // pieceAngle2x2TR
	2, // pieceAngle2x2BR
	2, // pieceAngle2x2BL
	1, // pieceSingle
    3, // newOne
    3, // newTwo
    2, // newThree
    2, // newFour
    3, // newFive,
    3, // new six
    3, // new seven
    2, // new eight
    2, // newNine
    3, // newTen
    3, // newEleven
    2, // newTwelve
    2, // newThirteen
    3, // newFourteen
    3, // newFifteen
};

constexpr board_index_t pieceHeight[] {
	0, // pieceNone
	5, // pieceLong5Vertical
	4, // pieceLong4Vertical
	3, // pieceLong3Vertical
	2, // pieceLong2Vertical
	1, // pieceLong5Horizontal
	1, // pieceLong4Horizontal
	1, // pieceLong3Horizontal
	1, // pieceLong2Horizontal
	3, // pieceSquare3x3
	2, // pieceSquare2x2
	3, // pieceAngle3x3TL
	3, // pieceAngle3x3TR
	3, // pieceAngle3x3BR
	3, // pieceAngle3x3BL
	2, // pieceAngle2x2TL
	2, // pieceAngle2x2TR
	2, // pieceAngle2x2BR
	2, // pieceAngle2x2BL
	1, // pieceSingle
    2, // newOne
    2, //newTwo
    3, //newThree
    3, //newFour
    3, //newFive
    2, //newSix
    2, //newSeven
    3, //newEight
    3, //newNine
    2, //newTen
    2, //newEleven
    3, // newTwelve
    3, // newThirteen
    2, // newFourteen
    2, // newFifteen
};

// the points given by each piece are just the number of squares
constexpr int piecePoints[] {
	0, // pieceNone
	5, // pieceLong5Vertical
	4, // pieceLong4Vertical
	3, // pieceLong3Vertical
	2, // pieceLong2Vertical
	5, // pieceLong5Horizontal
	4, // pieceLong4Horizontal
	3, // pieceLong3Horizontal
	2, // pieceLong2Horizontal
	9, // pieceSquare3x3
	4, // pieceSquare2x2
	5, // pieceAngle3x3TL
	5, // pieceAngle3x3TR
	5, // pieceAngle3x3BR
	5, // pieceAngle3x3BL
	3, // pieceAngle2x2TL
	3, // pieceAngle2x2TR
	3, // pieceAngle2x2BR
	3, // pieceAngle2x2BL
	1, // pieceSingle
    4, //newOne
    4, //newTwo
    4, //newThree
    4, //newFour
    8, //newFive
    4, //newSix
    4, //newSeven
    4, //newEight
    4, //newNine
    4, //newTen
    4, //newEleven
    4, //newTwelve
    4, //newThirteen
    4, // newFourteen
    4, // newFifteen
};

} // namespace raw