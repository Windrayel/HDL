#ifndef _CPU_H
#define _CPU_H

#include "systemc.h"

SC_MODULE(CPU)
{
    sc_in<bool>  clk_i;
    sc_in<message>   data_bi;
    sc_out<message>  data_bo;
    sc_out<bool> wr_o;
    sc_out<bool> rd_o;
    
    SC_HAS_PROCESS(CPU);
    
    CPU(sc_module_name nm);
    ~CPU();
    
    
    void mainThread();
    int unit_num;
private:

    void bus_write(int addr, int data);
    message bus_read();
    std::vector<double> neurons;
    std::vector<double> weights;
    double partial_sum;
    int size;
};


#endif
