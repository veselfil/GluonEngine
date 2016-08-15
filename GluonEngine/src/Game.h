﻿#pragma once

#include "Timer.h"
#include "Layer.h"
#include "Bundles.h"
#include <stack>
#include "Graphics/Window.h"

namespace ge
{

	class Game
	{
	public:
		virtual ~Game()
		{
		}

		Game(const std::string& title);

		virtual void OnInit() = 0;

		void OnUpdate();
		void OnRender();
		void OnDestroy();
		void _OnInit();

		void Start();
		void Stop();

		void PushLayer(Layer* layer);
		void PopLayer();

		void CreateWindow(unsigned int width, unsigned int height, bool fullscreen);
		void SetRenderer(ge::graphics::Renderer* renderer);

		ge::graphics::Window* GetWindow() const { return m_Window; }
		ge::graphics::RenderDevice* GetRenderDevice() const { return m_RenderDevice; }
		ge::graphics::Renderer* GetRenderer() const { return m_Renderer; }

	private:

		const std::string& m_Title;
		std::vector<Layer*> m_LayerStack;
		bool m_Running;

		ge::graphics::Window* m_Window;
		ge::graphics::RenderDevice* m_RenderDevice;
		ge::graphics::Renderer* m_Renderer;

		ge::RenderBundle* m_RenderBundle;
		ge::InitBundle* m_InitBundle;
		ge::UpdateBundle* m_UpdateBundle;

		void Run();
	};
};