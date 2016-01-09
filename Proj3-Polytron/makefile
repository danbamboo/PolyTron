#  Polytron makefile
#  
#  Created by Danny McMurrough on 7/25/15.
#   Copyright (c) 2015 Danny McMurrough. All rights reserved.

CXX=g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS= main.o
OBJS += creature.o
OBJS += barb.o
OBJS +=blue_men.o
OBJS +=gob.o
OBJS += reptile.o
OBJS += shadow.o
OBJS += battleField.o

SRCS = main.cpp
SRCS += creature.cpp
SRCS += barb.cpp
SRCS +=blue_men.cpp
SRCS +=gob.cpp
SRCS += reptile.cpp
SRCS += shadow.cpp
SRCS += battleField.cpp



All:${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o poly

${OBJS}:${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
clean:
	rm -rf ${OBJS} poly
