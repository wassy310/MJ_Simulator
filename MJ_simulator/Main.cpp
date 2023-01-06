# include <Siv3D.hpp>

void Field() {
	// whole
	Rect{
		50, 200, 1800, 300
	}.draw(Palette::Skyblue);
	Rect{
		50, 500, 1800, 300
	}.draw(Palette::Pink);
	// auto start
	Rect{
		50, 200, 150, 300
	}.drawFrame(0, 1, Palette::Black);
	Rect{
		50, 500, 150, 300
	}.drawFrame(0, 1, Palette::Black);
	// manual start
	Rect{
		1700, 200, 150
	}.drawFrame(0, 1, Palette::Black);
	Rect{
		1700, 650, 150
	}.drawFrame(0, 1, Palette::Black);
	// center (blue/red)
	Line{
		50, 500, 1850, 500
	}.draw(1, Palette::Black);
	// auto start
	Line{
		200, 200, 200, 800
	}.draw(1, Palette::Black);
	// cube area
	Line{
		1400, 200, 1400, 800
	}.draw(1, Palette::Black);
	// table
	Line{
		500, 200, 500, 800
	}.draw(1, Palette::Black);
	Line{
		800, 200, 800, 800
	}.draw(1, Palette::Black);
	Line{
		1100, 200, 1100, 800
	}.draw(1, Palette::Black);
}

void Table() {
	Circle{
			200, 400, 13
	}.draw()
		.drawFrame(0, 1, Palette::Black);
	Circle{
		500, 300, 13
	}.draw()
		.drawFrame(0, 1, Palette::Black);
	Circle{
		800, 400, 13
	}.draw()
		.drawFrame(0, 1, Palette::Black);
	Circle{
		1100, 300, 13
	}.draw()
		.drawFrame(0, 1, Palette::Black);
	Circle{
		1400, 400, 13
	}.draw()
		.drawFrame(0, 1, Palette::Black);
	Circle{
		200, 600, 13
	}.draw()
		.drawFrame(0, 1, Palette::Black);
	Circle{
		500, 700, 13
	}.draw()
		.drawFrame(0, 1, Palette::Black);
	Circle{
		800, 600, 13
	}.draw()
		.drawFrame(0, 1, Palette::Black);
	Circle{
		1100, 700, 13
	}.draw()
		.drawFrame(0, 1, Palette::Black);
	Circle{
		1400, 600, 13
	}.draw()
		.drawFrame(0, 1, Palette::Black);
}

void Robot() {
	Triangle{
		125, 350, 70
	}.draw(Palette::Blue);
	// Triangle{
	// 	1750, 275, 70
	// }.draw(Palette::Blue);
	Triangle{
		125, 650, 70
	}.draw(Palette::Red);
	Triangle{
		1750, 725, 70
	}.draw(Palette::Red);
}

void Main()
{
	Window::Resize(1900, 1000);

	const Vec2 defaultPosition(1750, 275);
	Vec2 pos = defaultPosition;

	while (System::Update())
	{
		//ClearPrint();
		//Print << U"frameBufferSize: " << Window::GetState().frameBufferSize;
		//Print << Cursor::PosF();

		Field();
		Table();
		Robot();

		const double delta = (Scene::DeltaTime() * 200);
		// 上下左右キーで移動
		if (KeyLeft.pressed()) {
			pos.x -= delta;
		}
		if (KeyRight.pressed()) {
			pos.x += delta;
		}
		if (KeyUp.pressed()) {
			pos.y -= delta;
		}
		if (KeyDown.pressed()) {
			pos.y += delta;
		}

		if (KeyC.down()) {
			pos = defaultPosition;
		}
		Triangle {
			pos, 70
		}.draw(Palette::Blue);
	}
}
