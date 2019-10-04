#include <QCoreApplication>
#include <windows.h>

#define BOX_WIDTH 400
#define BOX_HEIGHT 400
#define TIMEOUT 40
#define STEP 2

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int x, y, d;

    d = 0;
    x = GetSystemMetrics(SM_CXSCREEN) / 2 - BOX_WIDTH / 2;
    y = GetSystemMetrics(SM_CYSCREEN) / 2 - BOX_HEIGHT / 2;

    const int sx = x;
    const int sy = y;

    while (true) {
        if (GetAsyncKeyState(VK_ESCAPE)) {
            break;
        }

        SetCursorPos(x, y);

        switch (d) {
            case 0:
                if (x < sx + BOX_WIDTH) {
                    x += STEP;
                } else {
                    x = sx + BOX_WIDTH;
                    d++;
                }

                break;
            case 1:
                if (y < sy + BOX_HEIGHT) {
                    y += STEP;
                } else {
                    y = sy + BOX_HEIGHT;
                    d++;
                }

                break;
            case 2:
                if (x > sx) {
                    x -= STEP;
                } else {
                    x = sx;
                    d++;
                }

                break;
            case 3:
                if (y > sy) {
                    y -= STEP;
                } else {
                    y = sy;
                    d = 0;
                }

                break;
        }

        Sleep(TIMEOUT);
    }

    return a.exec();
}
