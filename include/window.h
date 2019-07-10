#ifndef INC_ROOMESCAPE_WINDOWS_H
#define INC_ROOMESCAPE_WINDOWS_H


class Window {
    private:
        const char* title_ = "RoomEscape";
        const char icon_ = '-';
        //размер для 16:9
        int window_x_ = 20;
        int window_y_ = 20;
        bool fullscreen_ = true;

    public:
        void Settings();
};

#endif
