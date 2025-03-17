export module File;

import Common;

export namespace ff {
class File {
  public:
	File(const Path& path);
	File(const File&) = delete;

  public:
	void load(const Path& path);

  protected:
	Path mPath;
	std::vector<Byte> mBuffer;
};
} // namespace ff
