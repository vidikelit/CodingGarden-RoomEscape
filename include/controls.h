#ifndef INC_ROOMESCAPE_CONTROLS_H
#define INC_ROOMESCAPE_CONTROLS_H


class Controls {
private:
    bool is_up_;
    bool is_down_;
    bool is_right_;
    bool is_left_;
    bool is_exit_;
public:
    bool IsUp() const;
    bool IsDown() const;
    bool IsRight() const;
    bool IsLeft() const;
    bool IsExit() const;
    void Update();
};


#endif
