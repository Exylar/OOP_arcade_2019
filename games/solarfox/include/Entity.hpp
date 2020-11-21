/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** Entity.hpp
*/

#ifndef C2E667D8_813E_42C9_82B0_CEB6CAD1C954
#define C2E667D8_813E_42C9_82B0_CEB6CAD1C954

class Entity {
    public:
        enum Direction {UP, LEFT, DOWN, RIGHT, IDLE};
    public:
        Entity()  {};
        ~Entity() {};
    
    public:
        void move();
        bool isCollide(const Entity &other) const;

    public:
        int getX() const {return _x;};
        int getY() const {return _y;};
        int getV() const {return _v;};
        int getWidth() const {return _width;};
        int getHeight() const {return _height;};
        Direction getDirection() const {return _dir;};
        
        void setX(int x) {_x = x;};
        void setY(int y) {_y = y;};
        void setV(int v) {_v = v;};
        void setWidth(int width) {_width = width;};
        void setHeigth(int height) {_height = height;};
        void setDirection(Direction dir) {_dir = dir;};

    protected:
        Direction _dir = IDLE;
        int _x = 0;
        int _y = 0;
        int _v = 0;
        int _width = 16;
        int _height = 16;
};

#endif /* C2E667D8_813E_42C9_82B0_CEB6CAD1C954 */
