using Godot;
using System;

public class Player : KinematicBody2D
{
    private const int MAX_SPD = 1000;
    private const int ACC = 1;
    private const int FRICTION = 10;
    private const int SLIDE_BUFF = 15;
    private const int GRAV = 20;
    private const int JMP_SPD = 500;
    private const int JMP_BUFF = 10;
    
    private Vector2 UP;
    private Vector2 vel;
    private int slideFrames = SLIDE_BUFF;
    private int jmpFrames = JMP_BUFF;
    private bool canJmp = true;

    // Called when the node enters the scene tree for the first time.
    public override void _Ready()
    {
        UP.x = 0;
        UP.y = -1;
    }

    // Called every frame. 'delta' is the elapsed time since the previous frame.
    public override void _PhysicsProcess(float delta)
    {
        float inp = Input.GetActionStrength("rht") - Input.GetActionStrength("lft");
        
        if (inp != 0)
        {
            if ((vel.x < 0 && inp > 0) || (vel.x > 0 && inp < 0))
                vel.x *= -0.5f;
            else
            {
                if (vel.x < MAX_SPD && vel.x > -MAX_SPD)
                    vel.x += inp * ACC;
            }
        }
        else if (--slideFrames <= 0)
        {
            if (vel.x > FRICTION * 2)
                vel.x -= FRICTION;
            else if (vel.x < FRICTION * -2)
                vel.x += FRICTION;
            else vel.x = 0;
        }
        
        if (IsOnFloor())
        {
            jmpFrames = JMP_BUFF;
            canJmp = true;
        }
        else if (--jmpFrames > 0)
            canJmp = true;
        else canJmp = false;
        
        if (Input.IsActionJustPressed("jmp") && canJmp)
            vel.y -= JMP_SPD;
        else vel.y += GRAV;
        
        vel = MoveAndSlide(vel, UP);
    }
}
