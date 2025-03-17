export module MidiFile;

import Common;
import File;

export namespace ff {
class MidiFile : public File {

  public:
	MidiFile(const Path& path);

  public:
	[[nodiscard]] bool isValid() const;

  private:
	void validate();

  private:
	bool mValid {false};
};
} // namespace ff
