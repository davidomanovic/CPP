
#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

/*
Declaration file for drawing emojis in a window
*/

// Abstract class. Inherited concrete classes must inherit draw().
class Emoji
{
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face : public Emoji
{
    // Facial features
    protected:
        Point centre; // Circle position
        int radius; // Circle radius
        
    public:
        Face(Point c, int r) : centre{c}, radius{r} {}; // Member initialization        
        void draw(AnimationWindow& w) override {w.draw_circle(centre, radius, Color::yellow);}
};

class EmptyFace : public Face
{
    protected:
        Point leftEye, rightEye;
        int eyeSize;
    
    public:
        EmptyFace(Point c, int r) : Face{c, r} {} // Delegating constructor
        
        void draw(AnimationWindow& win) override 
        {
            Face::draw(win); // draw face first
            
            eyeSize = 7; // Size of eye

            // Left eye
            rightEye = {centre.x + 21, centre.y - 10}; // Push up from centre 
            win.draw_circle(rightEye, eyeSize, Color::black);

            // Right eye
            leftEye = {centre.x - 21, centre.y - 10}; // Push up from centre 
            win.draw_circle(leftEye, eyeSize, Color::black);    
        }
};

class SmilingFace : public EmptyFace
{
    public:
        SmilingFace(Point c, int r) : EmptyFace{c, r} {}

        void draw(AnimationWindow& win) override
        {
            EmptyFace::draw(win);
            Point mouthPos = {centre.x, centre.y + 10};
            win.draw_arc(mouthPos, 30, 20, 180, 360, Color::black); // Draw mouth
        }

};

class SadFace : public EmptyFace
{   
    protected:
        Point sadMouthPos = {centre.x, centre.y + 20};

    public:
        SadFace(Point c, int r) : EmptyFace{c, r} {}
        void draw(AnimationWindow& win) override
        {
            EmptyFace::draw(win);
            win.draw_arc(sadMouthPos, 20, 10, 0, 180, Color::black); // Draw mouth
        }

        // Bruker dette alternativet fordi det skal være en unik objekt
};

class AngryFace :  public SadFace
{

    public:
        AngryFace(Point c, int r) : SadFace{c, r} {} 
    void draw(AnimationWindow& win) override
    {
        SadFace::draw(win); // Initialize face with eyes
        
        // Angry eyebrows
        win.draw_line({leftEye.x - 10, leftEye.y - 20}, {leftEye.x + 10, leftEye.y - 5});
        
        win.draw_line({rightEye.x + 10, rightEye.y - 20}, {rightEye.x - 10 , rightEye.y - 5});

    }

};

class WinkingFace : public SmilingFace
{
    public:
        WinkingFace(Point c, int r) : SmilingFace{c, r} {}

        void draw(AnimationWindow& win) override
        {
            SmilingFace::draw(win); // Steal from smiling face
            win.draw_circle(rightEye, eyeSize, Color::yellow); // remove eye
            win.draw_arc(rightEye, 10, 10, 0, 180); // Winking eye replacement
        }
};

class SurprisedFace : public EmptyFace
{
    public:
        SurprisedFace(Point c, int r): EmptyFace{c, r} {}

        void draw(AnimationWindow& win) override
        {
            EmptyFace::draw(win);
            win.draw_circle({centre.x, centre.y + 20}, 8, Color::black); // :O
        }
};
