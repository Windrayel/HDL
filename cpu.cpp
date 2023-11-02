#include "cpu.h"
#include "structures.h"

using namespace std;

CPU::CPU(sc_module_name nm)
    :sc_module(nm),
    clk_i("clk_i"),
    data_bi("data_bi"),
    data_bo("data_bo"),
    wr_o("wr_o"),
    rd_o("rd_o")
{
    wr_o.initialize(0);
    rd_o.initialize(0);
    
    SC_CTHREAD(mainThread, clk_i.pos());
    
}

CPU::~CPU()
{

}

void CPU::mainThread()
{
    int data_size = 5;
    message req{};
    
    do {
        req = bus_read();
        neurons.push_back(req.neuron);
        weights.push_back(req.weight);
    } while (!req.is_end);
    
    sc_stop();

}

message CPU::bus_read()
{
    return message{0, 0, 0, true, false};
}

void CPU::bus_write(int layer, int neuron)
{
    wait();
    data_bo.write(message{unit_num , 0, 0, false, true });
    wr_o.write(1);
    
    wait();
    wr_o.write(0);
}
