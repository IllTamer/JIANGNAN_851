#include "../../main.h"

#define MAX_SIZE 8
int Board[MAX_SIZE][MAX_SIZE];
int chessNumber;

// 棋盘覆盖
// 计算机算法设计与分析P21
/**
 * 判断特殊方格位置，将棋盘分成四快，若小棋盘无特殊方格，
 *      则用L型骨牌在原中心覆盖创造特殊棋盘，递归分治
 * @param sr 起始位置行号
 * @param sc 起始位置列号
 * @param dr 特殊方格行号
 * @param dc 特殊方格列号
 * @param size 棋盘边长
 * */
void ChessboardOverlay(int sr, int sc, int dr, int dc, int size) {
    if (size == 1) return;
    size /=  2;
    int chess = ++ chessNumber;
    // 特殊方格在左上角
    if (dr < sr+size && dc < sc+size) {
        ChessboardOverlay(sr, sc, dr, dc, size);
    } else {
        // L型覆盖右下角，更新特殊方格位置，分治
        int ndr = sr+size-1, ndc = sc+size-1;
        Board[ndr][ndc] = chess;
        ChessboardOverlay(sr, sc, ndr, ndc, size);
    }
    // 特殊方格在右上角
    if (dr < sr+size && dc >= sc+size) {
        ChessboardOverlay(sr, sc+size, dr, dc, size);
    } else {
        // L型覆盖左下角，更新特殊方格位置，分治
        int ndr = sr+size-1, ndc = sc+size;
        Board[ndr][ndc] = chess;
        ChessboardOverlay(sr, sc+size, ndr, ndc, size);
    }
    // 特殊方格在左下角
    if (dr >= sr+size && dc < sc+size) {
        ChessboardOverlay(sr+size, sc, dr, dc, size);
    } else {
        // L型覆盖右上角，更新特殊方格位置，分治
        int ndr = sr+size, ndc = sc+size-1;
        Board[ndr][ndc] = chess;
        ChessboardOverlay(sr+size, sc, ndr, ndc, size);
    }
    // 特殊方格在右下角
    if (dr >= sr+size && dc >= sc+size) {
        ChessboardOverlay(sr+size, sc+size, dr, dc, size);
    } else {
        // L型覆盖左上角，更新特殊方格位置，分治
        int ndr = sr+size, ndc = sc+size;
        Board[ndr][ndc] = chess;
        ChessboardOverlay(sr+size, sc+size, ndr, ndc, size);
    }
}

int main() {
    int dr = 0, dc = 3;
    Board[dr][dc] = -1;
    ChessboardOverlay(0, 0, dr, dc, MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; ++i) {
        for (int j = 0; j < MAX_SIZE; ++j) {
            printf("%5d ", Board[i][j]);
        }
        printf("\n");
    }
}