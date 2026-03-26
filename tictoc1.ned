//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2003 Ahmet Sekercioglu
// Copyright (C) 2003-2015 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//
channel Delayed extends ned.DelayChannel {
    delay = 10ms;
}

simple Txc1
{
    parameters:
        @signal[hopCount](type=int);
        @signal[delayVec](type=simtime_t);

        @statistic[hopCount](title="Hop Count"; source=hopCount; record=last);
        @statistic[delayVec](title="Inter-send Delay"; source=delayVec; record=vector);
    gates:
        input in;
        output out;
}

network Tictoc1
{
    submodules:
        tic: Txc1;
        toc: Txc1;
    connections:
        tic.out --> Delayed --> toc.in;
        toc.out --> Delayed --> tic.in;
}

