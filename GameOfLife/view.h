#ifndef VIEW_H
#define VIEW_H

class IView {
public:
    virtual ~IView() = default;
    virtual void display(const Grid& grid) const = 0;
    virtual void update(const Grid& grid) const = 0;
};

class ViewConsole : public IView {
// classe à remplir avec vue sfml
};

#endif