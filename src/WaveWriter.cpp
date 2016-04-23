#include "WaveWriter.h"

WaveWriter::WaveWriter() {
}

WaveWriter::WaveWriter(std::string fname) {
}

void WaveWriter::open (std::string fname) {
  // Open the soundfile for output.
  try {
    output = new stk::FileWvOut(fname, 1, stk::FileWrite::FILE_WAV );
  }
  catch ( stk::StkError & ) {
    // need to process the error
  }
}

void WaveWriter::close() {
  if (output != NULL) {
    output->closeFile();
  }
}

void WaveWriter::write(float value) {
  output->tick(value);    
}

WaveWriter::~WaveWriter() {
  if (output != NULL) {
      delete output;
  }
}

