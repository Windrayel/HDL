#ifndef _IO_CONTROLLER_H
#define _IO_CONTROLLER_H

#include <systemc.h>

SC_MODULE(IO_contr)
{
    sc_in<bool>  clk_i;
    sc_out<int>   addr_bo;
    sc_out<double>  data_bo;
    sc_out<bool>  wr_o;
    sc_out<bool>  rd_o;

    SC_HAS_PROCESS(IO_contr);

    IO_contr(sc_module_name nm);
    ~IO_contr();

    void bus_write(int addr, double data);
    //void bus_read(int addr);
    void write_image();

private:
    std::vector<double> input;
    std::vector<double> output;
};

#endif
