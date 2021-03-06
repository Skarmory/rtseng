#include "editor_state.h"

#include "services.h"

EditorState* EditorState::current = nullptr;

void TexturePaintState::execute(void)
{
	const Mouse& mouse = Services::get().get_input_manager()->get_mouse();

	if (mouse.pressed(MouseButtonType::Button_1))
	{
		Event paint_tex_event;
		paint_tex_event.event_type = "PaintTextureEvent";

		Services::get().get_event_manager()->dispatch(paint_tex_event);
	}
	else if (mouse.pressed(MouseButtonType::Button_2) || mouse.scroll() != 0.0f)
	{
		Event move_camera;
		move_camera.event_type = "MoveCameraEvent";

		Services::get().get_event_manager()->dispatch(move_camera);
	}
}

void HeightDeformState::execute(void)
{
	const Mouse& mouse = Services::get().get_input_manager()->get_mouse();

	if (mouse.pressed(MouseButtonType::Button_1))
	{
		Event paint_tex_event;
		paint_tex_event.event_type = "HeightDeformEvent";

		Services::get().get_event_manager()->dispatch(paint_tex_event);
	}
	else if (mouse.pressed(MouseButtonType::Button_2) || mouse.scroll() != 0.0f)
	{
		Event move_camera;
		move_camera.event_type = "MoveCameraEvent";

		Services::get().get_event_manager()->dispatch(move_camera);
	}
}

void UnitPlaceState::execute(void)
{
	const Mouse& mouse = Services::get().get_input_manager()->get_mouse();

	if (mouse.released(MouseButtonType::Button_1))
	{
		Event unit_place_request;
		unit_place_request.event_type = "UnitPlaceRequestEvent";

		Services::get().get_event_manager()->dispatch(unit_place_request);
	}
	else if (mouse.pressed(MouseButtonType::Button_2) || mouse.scroll() != 0.0f)
	{
		Event move_camera;
		move_camera.event_type = "MoveCameraEvent";

		Services::get().get_event_manager()->dispatch(move_camera);
	}
}

void ObjectPlaceState::execute(void)
{
	const Mouse& mouse = Services::get().get_input_manager()->get_mouse();

	if (mouse.released(MouseButtonType::Button_1))
	{
		Event object_place_request;
		object_place_request.event_type = "ObjectPlaceRequestEvent";

		Services::get().get_event_manager()->dispatch(object_place_request);
	}
	else if (mouse.pressed(MouseButtonType::Button_2) || mouse.scroll() != 0.0f)
	{
		Event move_camera;
		move_camera.event_type = "MoveCameraEvent";

		Services::get().get_event_manager()->dispatch(move_camera);
	}
}