#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Apr 19 20:03:07 2020

@author: averkepasa
"""


class State:
    def __init__(self, numbers):
        self.numbers = numbers.copy()
    def printRow(self, i):
        for j in range(0,3):
            print(self.numbers[i][j])
    def print(self):
        for i in range(0,3):
            for j in range(0,3):
                print(self.numbers[i][j], ' ')
            print('')
            
state = State([[1,2,3],[4,5,6],[0,0,0]])
state.numbers[1][1] = 4
state.print()
        