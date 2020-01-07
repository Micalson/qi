#include <osgWrapper/RenderView.h>
#include <osgWrapper/RenderScene.h>

#include <osgWrapper/RenderService.h>

#include <iostream>
namespace OSGWrapper 
{

RenderView::RenderView()
	:m_frame_id(0)
	,m_suppress(false)
	,m_width(50)
	,m_height(50)
{
	addEventHandler(new GUIHandlerProxy<RenderView>(*this));

	m_root = new osg::ClearNode();
	setSceneData(m_root);

	m_ui_panel = new UIPanel();
	//m_root->addChild(m_ui_panel);
	m_ui_root = new UIRoot();
	m_root->addChild(m_ui_root);
}

RenderView::~RenderView()
{
}

void RenderView::AddGlobalUniform(osg::Uniform* uniform)
{
	m_root->getOrCreateStateSet()->addUniform(uniform, state_on);
}

void RenderView::SetBackgroundColor(const osg::Vec4& color)
{
	m_root->setClearColor(color);
}

bool RenderView::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	bool result = false;
	switch(ea.getEventType())
	{
	case osgGA::GUIEventAdapter::RESIZE:
		{
			result = handleResizeEvent(ea, aa);
			break;
		}
	case osgGA::GUIEventAdapter::FRAME:
		{
			result = handleFrameEvent(ea, aa);
			break;
		}
	case osgGA::GUIEventAdapter::KEYDOWN:
	case osgGA::GUIEventAdapter::KEYUP:
		{
			result = handleKeyEvent(ea, aa);
			break;
		}
	case osgGA::GUIEventAdapter::RELEASE:
	case osgGA::GUIEventAdapter::PUSH:
	case osgGA::GUIEventAdapter::DRAG:
	case osgGA::GUIEventAdapter::MOVE:
	case osgGA::GUIEventAdapter::SCROLL:
		{
			result = handleMouseEvent(ea, aa);
			break;
		}
	case osgGA::GUIEventAdapter::DOUBLECLICK:
		{
			result = handleDoubleClickEvent(ea, aa);
			break;
		}
	default:
		result = false;
	}

	return result;
}

bool RenderView::handleResizeEvent(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	int w = ea.getWindowWidth();
	int h = ea.getWindowHeight();
	if (w == m_width && h == m_height)
		return false;

	m_width = w;
	m_height = h;

	//m_ui_panel->Resize((float)m_width, (float)m_height);
	m_ui_root->Resize((float)m_width, (float)m_height);
	if(m_current_scene)
	{
		osg::Viewport* view_port = _camera->getViewport();
		if(view_port) m_current_scene->setViewport(view_port->x(), view_port->y(), view_port->width(), view_port->height());

		m_current_scene->UpdateViewport();
		m_current_scene->OnResize(ea, aa);
		m_current_scene->SetSize((unsigned)m_width, (unsigned)m_height);
	}
	std::cout<<"OSG Resize Event."<<std::endl;
	return true;
}

bool RenderView::handleFrameEvent(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	++m_frame_id;

	if (m_frame_id < 30)
	{
		osg::Viewport* view_port = _camera->getViewport();
		if (view_port)
		{
			m_width = (int)view_port->width();
			m_height = (int)view_port->height();
			m_ui_panel->Resize(m_width, m_height);
			m_ui_root->Resize(m_width, m_height);
		}
	}
	//std::cout<<"OSG Frame Event."<<std::endl;
	//m_ui_panel->handleFrameEvent(ea, aa);
	m_ui_root->handleFrameEvent(ea, aa);
	if(m_current_scene.valid()) m_current_scene->OnFrame(ea, aa);

	return true;
}

bool RenderView::handleKeyEvent(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	if (m_ui_root->handleKeyEvent(ea, aa))
		return true;
	//std::cout<<"OSG Key Event."<<std::endl;
	//if (m_ui_panel->handleKeyEvent(ea, aa))
	//	return true;
	if(m_current_scene.valid()) m_current_scene->OnKey(ea, aa);
	return true;
}

bool RenderView::handleMouseEvent(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	if (m_ui_root->handleMouseEvent(ea, aa))
		return true;
	//if (m_ui_panel->handleMouseEvent(ea, aa))
	//	return true;
	if(m_current_scene.valid()) m_current_scene->OnMouse(ea, aa);
	//std::cout<<"OSG Mouse Event."<<std::endl;
	return true;
}

bool RenderView::handleDoubleClickEvent(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	if (m_ui_root->handleDoubleClickEvent(ea, aa))
		return true;
	//if (m_ui_panel->handleDoubleClickEvent(ea, aa))
	//	return true;
	if(m_current_scene.valid()) m_current_scene->OnDoubleClick(ea, aa);
	//std::cout<<"OSG Double Click Event."<<std::endl;
	return true;
}

void RenderView::SetCurrentScene(RenderScene* scene, bool save_preview_scene)
{
	osg::Viewport* view_port = _camera->getViewport();
	if (view_port)
	{
		m_width = (int)view_port->width();
		m_height = (int)view_port->height();
	}
	if(scene && view_port)
		if(view_port) scene->setViewport(view_port->x(), view_port->y(), view_port->width(), view_port->height());
	
	{
		if(m_current_scene.get() && !save_preview_scene)
		{
			m_current_scene->AttachRenderView(0);
			m_current_scene->OnEnterOut();
			//m_current_scene->OnEnterOutUI(m_ui_panel);
			m_current_scene->OnEnterOutUI(m_ui_root);
		}
		m_root->removeChild(m_current_scene);
		//m_root->removeChildren(0, m_root->getNumChildren());
		if(scene)
		{
			scene->AttachRenderView(this);
			scene->OnEnter();
			scene->OnEnterUI(m_ui_root);
			//scene->OnEnterUI(m_ui_panel);
			m_root->insertChild(0, scene);
		}
	}
	
	m_preview_scene = 0;
	if(save_preview_scene)
		m_preview_scene = m_current_scene;
	m_current_scene = scene;

	if (m_current_scene)
	{
		m_current_scene->UpdateViewport();
		m_current_scene->SetSize((unsigned)m_width, (unsigned)m_height);
	}
}

bool RenderView::RollbackScene()
{
	if(m_current_scene == m_preview_scene || !m_preview_scene)
		return false;

	m_root->removeChild(m_current_scene);
	//m_root->removeChildren(0, m_root->getNumChildren());
	//m_root->addChild(m_preview_scene);
	m_root->insertChild(0, m_preview_scene);

	m_current_scene = m_preview_scene;
	m_preview_scene = 0;
	return true;
}

void RenderView::SyncWork()
{
	if (m_current_scene) m_current_scene->SyncWork();
}

void RenderView::SetGlobalUI(UIItem* item)
{
	//m_ui_panel->SetGlobalUI(item);
}

UIRoot* RenderView::GetUIRoot()
{
	return m_ui_root;
}

}