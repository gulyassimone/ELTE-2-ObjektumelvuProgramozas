#ifndef SERVICESTATION_H
#define SERVICESTATION_H


class Pump
{
    public:
        Pump(): _display(0) {};
        void fill(int liter){_display=liter;};
        void clearFuel() {_display=0;};
        int getDisplay() {return _display;};
    private:
        int _display;
};

#endif // SERVICESTATION_H
