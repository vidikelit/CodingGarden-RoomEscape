#ifndef INC_ROOMESCAPE_CONTROLS_H
#define INC_ROOMESCAPE_CONTROLS_H


class Controls {
private:
    bool is_up_;
    bool is_down_;
    bool is_right_;
    bool is_left_;
    bool is_e;
    bool is_exit_;
public:
    bool isUp() const;
    bool isDown() const;
    bool isRight() const;
    bool isLeft() const;
    bool isExit() const;
    bool isE() const;

    void Update();
};


#endif
