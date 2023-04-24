/*
Make a window and draw emojis with the Emoji.h class.
*/

#include "emoji.h"

constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{
	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

	vector<unique_ptr<Emoji>> emojis;
    emojis.emplace_back(new SmilingFace({100, 100}, emojiRadius));
    emojis.emplace_back(new SadFace({200, 100}, emojiRadius));
    emojis.emplace_back(new AngryFace({200, 300}, emojiRadius));
    emojis.emplace_back(new WinkingFace({300, 300}, emojiRadius));
    emojis.emplace_back(new SurprisedFace({100, 300}, emojiRadius));

    for (int i = 0; i < emojis.size(); i++)
    {
        emojis.at(i) -> draw(win);
    }

	win.wait_for_close();

	return 0;
}
