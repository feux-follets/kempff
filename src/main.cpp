import MidiFile;
import Common;

#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_sdlrenderer3.h>

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

struct SDL_Deleter {
	void operator()(SDL_Window* p) const { SDL_DestroyWindow(p); }

	void operator()(SDL_Renderer* p) const { SDL_DestroyRenderer(p); }

	void operator()(SDL_Texture* p) const { SDL_DestroyTexture(p); }
};

int main() {
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD)) {
		fmt::println("Error: SDL_Init(): {}", SDL_GetError());
		return -1;
	}
	const SDL_WindowFlags windowFlags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN;
	auto window = std::unique_ptr<SDL_Window, SDL_Deleter>(SDL_CreateWindow("Test Example", 1280, 720, windowFlags),
														   SDL_Deleter());
	if (window == nullptr) {
		fmt::println("Error: SDL_CreateWindow(): {}", SDL_GetError());
		return -1;
	}
	auto renderer = std::unique_ptr<SDL_Renderer, SDL_Deleter>(SDL_CreateRenderer(window.get(), nullptr));
	SDL_SetRenderVSync(renderer.get(), 1);
	if (renderer == nullptr) {
		fmt::println("Error: SDL_CreateRenderer(): {}", SDL_GetError());
		return -1;
	}
	SDL_SetWindowPosition(window.get(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	SDL_ShowWindow(window.get());

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

	ImGui::StyleColorsDark();

	ImGui_ImplSDL3_InitForSDLRenderer(window.get(), renderer.get());
	ImGui_ImplSDLRenderer3_Init(renderer.get());

	bool done = false;
	while (!done) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			ImGui_ImplSDL3_ProcessEvent(&event);
			if (event.type == SDL_EVENT_QUIT) {
				done = true;
			}
			if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED &&
				event.window.windowID == SDL_GetWindowID(window.get())) {
				done = true;
			}
		}
		ImGui_ImplSDLRenderer3_NewFrame();
		ImGui_ImplSDL3_NewFrame();
		ImGui::NewFrame();

		ImGui::ShowDemoWindow(nullptr);
		ImGui::Render();

		SDL_SetRenderDrawColorFloat(renderer.get(), 0.45, 0.55, 0.65, 1);
		SDL_RenderClear(renderer.get());
		ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer.get());
		SDL_RenderPresent(renderer.get());
	}

	ImGui_ImplSDLRenderer3_Shutdown();
	ImGui_ImplSDL3_Shutdown();
	ImGui::DestroyContext();

	SDL_Quit();
	return 0;
}
