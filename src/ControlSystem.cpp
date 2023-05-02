#include "ControlSystem.hpp"

ControlSystem::ControlSystem(double dt)
    : E1("enc1"), E2("enc2"),
      timedomain("Main time domain", dt, true)
{
    // Name all blocks
    E1.setName("E1");
    E2.setName("E2");

    // Name all signals
    E1.getOut().getSignal().setName("q1 [rad]");
    E2.getOut().getSignal().setName("q2 [rad]");

    // Connect signals

    // Add blocks to timedomain
    timedomain.addBlock(E1);
    timedomain.addBlock(E2);

    // Add timedomain to executor
    eeros::Executor::instance().add(timedomain);
}