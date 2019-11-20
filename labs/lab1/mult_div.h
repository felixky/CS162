struct mult_div_values {
   int mult;
   float div;
};
void check(int &rows,int &cols);
void set_mult_values(mult_div_values **table, int m, int n);
void set_div_values(mult_div_values **table, int m, int n);
void delete_table(mult_div_values **table, int m, int n);   
struct mult_div_values** create_table(mult_div_values **table, int m, int n);
