#include <Siv3D.hpp>

void Field() {
	// 全体
	Rect{
		50, 200, 1800, 300
	}.draw(Palette::Skyblue);
	Rect{
		50, 500, 1800, 300
	}.draw(Palette::Pink);
	// 自動機スタートゾーン
	Rect{
		50, 200, 150, 300
	}.drawFrame(0, 1, Palette::Black);
	Rect{
		50, 500, 150, 300
	}.drawFrame(0, 1, Palette::Black);
	// 手動機スタートゾーン
	Rect{
		1700, 200, 150
	}.drawFrame(0, 1, Palette::Black);
	Rect{
		1700, 650, 150
	}.drawFrame(0, 1, Palette::Black);
	// 中央分離帯的な
	Line{
		50, 500, 1850, 500
	}.draw(1, Palette::Black);
	// 自動機スタートゾーン
	Line{
		200, 200, 200, 800
	}.draw(1, Palette::Black);
	// キューブエリア
	Line{
		1400, 200, 1400, 800
	}.draw(1, Palette::Black);
	// テーブルのところ
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
	// ロボットの大きさを変えたいとき -> '70'(1辺の長さ)を変える
	constexpr Triangle triangle_ba{		// 青ゾーン、自動機
		125, 350, 70
	};
	triangle_ba.rotated(90_deg).draw(Palette::Blue);

	constexpr Triangle triangle_ra{		// 赤ゾーン、自動機
		125, 650, 70
	};
	triangle_ra.rotated(90_deg).draw(Palette::Red);

	constexpr Triangle triangle_rm{		// 赤ゾーン、手動機
		1750, 725, 70
	};
	triangle_rm.rotated(40_deg).draw(Palette::Red);
}

void Main() {
	Field();
	Table();
	Robot();

	Window::Resize(1900, 1000);

	const double Radius = 13.0;

	// 円座標の配列
	Array<Vec2> circlePositions
	{
	  {200, 400},{500, 300},{800, 400}, {1100, 300}, {1400, 400}, {200, 600}, {500, 700}, {800, 600}, {1100, 700}, {1400, 600}
	};

	// 三角形のデフォルト座標
	const Vec2 DefaultPosition{ 1750, 275 };

	// 三角形の座標 
	Vec2 trianglePos{ 0, 0 };

	while (System::Update()) {
		const double delta = (Scene::DeltaTime() * 200);

		if (KeyLeft.pressed()) {
			trianglePos.x -= delta;
		}

		if (KeyRight.pressed()) {
			trianglePos.x += delta;
		}

		if (KeyUp.pressed()) {
			trianglePos.y -= delta;
		}

		if (KeyDown.pressed()) {
			trianglePos.y += delta;
		}

		if (KeyC.down()) {
			trianglePos = DefaultPosition;
		}

		// 三角形の描画
		Triangle{ trianglePos, 70 }.draw();

		// 円の描画
		for (const auto& pos : circlePositions) {
			Circle{ pos, Radius }.draw();
		}

		// これより大きい数は最短距離にならない
		double distance = 999999.0;

		// 最短距離の算出
		for (const auto& pos : circlePositions) {
			distance = Min(distance, trianglePos.distance(pos));
		}

		// 最短距離の表示
		Print << distance;
	}
}
