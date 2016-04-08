TARGET:= ./main
SRC_DIR:= ./
INC_DIR:= ./
SRCS:= $(wildcard  *.cc)
CXX:= g++
LIBS:= -lpthread
CXXFLAGS:= -g -w $(LIBS) $(addprefix -I, $(INC_DIR))

$(TARGET):$(SRCS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -rf $(TARGET)
