//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2003 Ahmet Sekercioglu
// Copyright (C) 2003-2015 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//
#include <cstring>
#include <omnetpp.h>
using namespace omnetpp;

class Txc1 : public cSimpleModule
{
  private:
    simsignal_t hopCountSignal;
    simsignal_t delayVecSignal;
    int hopCount = 0;
    simtime_t lastSend = SIMTIME_ZERO;

  protected:
    void initialize() override {
        hopCountSignal = registerSignal("hopCount");
        delayVecSignal = registerSignal("delayVec");

        emit(hopCountSignal, hopCount);
        emit(delayVecSignal, SIMTIME_ZERO);
        lastSend = simTime();

        if (strcmp("tic", getName()) == 0)
            send(new cMessage("tictocMsg"), "out");
    }

    void handleMessage(cMessage *msg) override {
        hopCount++;
        emit(hopCountSignal, hopCount);
        emit(delayVecSignal, simTime() - lastSend);
        lastSend = simTime();
        send(msg, "out");
    }
};

Define_Module(Txc1);
