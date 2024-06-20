CC = gcc

BUILD_DIR = build
SRC_DIR = src
INC_DIR = includes

APP_NAME = nlvm
APP = $(BUILD_DIR)/$(APP_NAME)

CFLAGS = -g -O0 -I$(SRC_DIR) -I$(INC_DIR)
LDFLAGS = -lm 

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

all: always clean $(APP)
	cp $(APP) ./$(APP_NAME)

$(APP): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -fr $(BUILD_DIR)/* ./$(APP_NAME)

always:
	mkdir -p $(BUILD_DIR)

