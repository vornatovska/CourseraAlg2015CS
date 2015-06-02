class Jordan{
    private:
        int NEQ, N1;
        float **A;
    public:
        Jordan(); 
        ~Jordan();
        void setJordan();        
        void doCalculate();
        void fromFile();
};

