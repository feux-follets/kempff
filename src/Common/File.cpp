module File;

namespace ff {
File::File(const Path& path) : mPath(path) {
	load(mPath);
}

void File::load(const Path& path) {
	const auto fileSize = fs::file_size(path);
	mBuffer.resize(fileSize);
	std::ranges::fill(mBuffer, 0);
	std::ifstream file(path, std::ios::binary);
	file.read(reinterpret_cast<char*>(mBuffer.data()), mBuffer.size());
}

} // namespace ff
