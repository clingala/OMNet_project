Assignment 1 — OMNeT++ Install & Sanity Check (TicToc)
=====================================================
Student Name: Chandana Lingala           NetID: clingala            Date: 2025-09-28
OS/Path Used (circle one): macOS / Windows WSL2 / Linux
Chosen Path: Linux (Ubuntu, native)

1) Build & Run
   - OMNeT++ root path: ~/omnetpp-6.2.0
   - OMNeT++ version: 6.2.0 (built with clang, MODE=debug)
   - Environment commands used:
       . setenv
       ./configure
       make -j$(nproc)
   - Sample build & run commands:
       cd ~/omnetpp-6.2.0/samples/tictoc
       make MODE=debug
       out/clang-debug/tictoc_dbg -u Cmdenv -c General
   - Did 'tictoc' build successfully?  YES

2) Model Edit
   - What connection did you delay?  tic ↔ toc (both directions)
   - Delay value used: 10ms
   - Edit location: samples/tictoc/tictoc1.ned
   - Edit summary: added a named channel:
         channel Delayed extends ned.DelayChannel { delay = 10ms; }
     and used:
         tic.out --> Delayed --> toc.in;
         toc.out --> Delayed --> tic.in;

3) Results
   - Scalar recording enabled: **.scalar-recording = true
   - Vector recording enabled: **.vector-recording = true
   - Scalar file path (.sca):   samples/tictoc/results/General-#0.sca
   - Vector file path (.vec):   samples/tictoc/results/General-#0.vec

4) Notes / Issues Encountered (2–4 lines):
   - Resolved ./configure error by creating Python venv and installing requirements:
       python3 -m venv .venv && source .venv/bin/activate && pip install -r python/requirements.txt
   - Built samples with MODE=debug to avoid missing 'clang-release' artifacts.
   - Added 'network = Tictoc1' to [General] in omnetpp.ini to fix “No network specified”.

Screenshots included:
   01_cli_run.png — Successful Cmdenv run output
   02_ned_edit.png — Edited tictoc1.ned showing Delayed channel
   03_gui_run.png — (optional) Qtenv animation window
