//@result Submitted a few seconds ago • Score: 15.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0s Test Case #7: 0s Test Case #8: 0s Test Case #9: 0s Test Case #10: 0s

class Rectangle {
public:
    Rectangle(void) : width(0), height(0) {}
    void Display(void) {
        cout << width << " " << height << endl;
    }
protected:
    int width;
    int height;
};
class RectangleArea : public Rectangle {
public:
    void Input(void) {
        cin >> width >> height;
    }
    void Display(void) {
        cout << width * height << endl;
    }
};
