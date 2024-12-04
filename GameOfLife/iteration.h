class IIteration {
protected:
    int generations;
    int currentIteration;

public :
    virtual ~IIteration() = default;
    IIteration(){nombre_iteration=0;};
    virtual int Calcul_Iteration ();
};

class iteration_classique: public IIteration {
    int Calcul_Iteration() override {
        int nombre_iteration =+ 1;
        return nombre_iteration;
    }
};