using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public static GameManager Me;

    public ParticleSystem explosion;

    public ParticleSystem collision;

    public static GameManager GM
    {
        get
        {
            return Me;
        }
    }

    private void Awake()
    {
        DontDestroyOnLoad(gameObject);
        Me = this;
    }

    public void AsteroidDestroyed(AsteroidDamage asteroid)
    {
        this.explosion.transform.position = asteroid.transform.position;
        this.explosion.Play();
    }

    public void Invader1Destroyed(BlueDamage invader1)
    {
        this.explosion.transform.position = invader1.transform.position;
        this.explosion.Play();
    }

    public void Invader3Destroyed(Lilac invader3)
    {
        this.explosion.transform.position = invader3.transform.position;
        this.explosion.Play();
    }  

    public void BulletColl(Bullet bullet)
    {
        this.collision.transform.position = bullet.transform.position;
        this.collision.Play();
    }

    public void Missile(Missile2 missile)
    {
        this.collision.transform.position = missile.transform.position;
        this.collision.Play();
    }

    public void Missile(Missile missile)
    {
        this.collision.transform.position = missile.transform.position;
        this.collision.Play();
    }
}
