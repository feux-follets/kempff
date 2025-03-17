module MidiFile;

import Utility;

namespace ff {
MidiFile::MidiFile(const Path& path) : File(path) {
}

bool MidiFile::isValid() const {
	return mValid;
}

void MidiFile::validate() {
	// Check header
}
} // namespace ff
