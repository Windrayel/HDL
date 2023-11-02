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


    message msg{};
    do {
        msg = bus_read();
        neurons.push_back(msg.neuron);
        weights.push_back(msg.weight);
    } while (!msg.is_end);
    for (int i = 0; i < neurons.size(); i++) {
        partial_sum += neurons[i] * weights[i];
    }


    
    sc_stop();

}

message CPU::bus_read()
{
    return message{0, 0, 0, true, false};
}

void CPU::bus_write(int layer, int neuron, bool is_req)
{
    wait();
    data_bo.write(message{unit_num , 0, 0, false, true });
    wr_o.write(1);
    
    wait();
    wr_o.write(0);
}
