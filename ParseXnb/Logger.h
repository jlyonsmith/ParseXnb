#pragma once


// Helper for writing formatted text to the console output.
class Logger
{
public:
    Logger();

    void Indent()   { indentation++; }
    void Unindent() { indentation--; }

    void Write(char const* format, ...);
    void WriteLine(char const* format, ...);
    void WriteBytes(char const* name, vector<uint8_t> const& bytes);
    void WriteEnum(char const* name, int32_t value, char const* const* enumValues);

private:
    void Write(char const* format, va_list args);

    int indentation;
    bool isNewLine;
};
