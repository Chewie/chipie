#include <cstdint>
#include <array>
#include <stack>

class Chip8
{
    // Current opcode
    uint16_t opcode;

    // VM Memory, mapped as follow:
    // 0x000-0x1FF are reserved for the interpreter
    // 0x200-0xFFF contain ROM and RAM
    std::array<uint8_t, 4096> memory;

    // General purpose registers
    uint8_t V[16];

    // Index register and Program Counter.
    // These registers can have values from 0x000 to 0xFFF
    uint16_t I;
    uint16_t pc;

    // The screen is a 64x32 matrix of black or white pixels
    std::array<bool, 64 * 32> screen;

    // Chip8 has no hardware interrupts, it provides insteads these timers
    // The timers tick down at 60Hz when above zero
    uint8_t delay_timer;
    uint8_t sound_timer;

    // We need to store the pc when we jump
    std::stack<uint8_t> stack;

    // Current state of the 16 key presses
    std::array<bool, 16> keys_pressed;

};
