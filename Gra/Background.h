//#ifndef BACKGROUND_H
//#define BACKGROUND_H
//#include "posrednik.h"

//void Display_Backgrounds(float windowx, float windowy)
//{


//    Texture spacebacktex;
//    Texture spacebacktex2;
//    Sprite spacebacksprite;
//    Sprite spacebacksprite2;
//    spacebacktex.loadFromFile("tex/space.png");
//    spacebacktex2.loadFromFile("tex/space.png");
//    ///background
//    spacebacktex.setRepeated(true);
//    spacebacksprite.setTexture(spacebacktex);
//    spacebacksprite.setTextureRect(sf::IntRect(0, 0, 800,600));

//		if (starfield3_sprite_count <= 5 && bg_anim_forw == true)
//		{
//			if (frame % (6 * ts_inv) == 0)
//			starfield3_sprite_count++;
//			if (starfield3_sprite_count == 5)
//			{
//			bg_anim_forw = false;
//			starfield3_sprite_count = 4;
//			}
//		}
//		else if (starfield3_sprite_count >= 0 && bg_anim_forw == false)
//		{
//			if (frame % (6 * ts_inv) == 0)
//			starfield3_sprite_count--;
//			if (starfield3_sprite_count == 0)
//			bg_anim_forw = true;
//		}


//	spacebacksprite = starfield1[part_count % 3][starfield3_sprite_count];
//	spacebacksprite2 = starfield1[(part_count + 1) % 3][starfield3_sprite_count];
//	spacebacksprite.SetPosition(background_x, 0 - (camera.Top * 0.1));
//	spacebacksprite2.SetPosition(background_x + 2048, 0 - (camera.Top * 0.1));
//	App.Draw(spacebacksprite);
//	App.Draw(spacebacksprite2);
//	star_overlay.SetPosition(background_x*2, 0 - (camera.Top * 0.2));
//	App.Draw(star_overlay);
//}
//#endif // BACKGROUND_H
