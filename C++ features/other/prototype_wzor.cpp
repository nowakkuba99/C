#include <vector>

class Widget{
public:
    virtual Widget* clone() = 0;
    virtual ~Widget() = default;
};

class Button: public Widget{
public:
    Widget* clone() override
    {
        return new Button(*this);     
    }
};

class Label: public Widget{
public:
    Widget* clone() override
    {
        return new Label(*this);   
    }
};

class Panel{
    std::vector<Widget*> vec;
public:
    void add(Widget* elem)
    {
        vec.push_back(elem);
    }
    Panel() = default;
    Panel(const Panel& panelToCopy)
    {
        for (auto widget: panelToCopy.vec)
        {
            vec.push_back(widget->clone());
        }
    }
    ~Panel()
    {
        for (auto widget: vec)
        {
            delete widget;
        }
    }
};

int main()
{
    Panel p1;
    p1.add(new Button);
    p1.add(new Label);

    Panel p2(p1);

    return 0;
}

