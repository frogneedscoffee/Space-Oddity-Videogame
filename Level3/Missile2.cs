using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Missile2 : MonoBehaviour
{
    public Vector3 direction;

    public float speed;

    private void Start()
    {
        Destroy(this.gameObject, 4.0f);
    }

    private void Update()
    {
        this.transform.position += this.direction * this.speed * Time.deltaTime;
    }

    private void OnTriggerEnter2D(Collider2D other)
    {
        if (other.gameObject.layer == LayerMask.NameToLayer("Player"))
        {
            other.gameObject.GetComponent<PlayerDamage>().life -= 1;
            Destroy(this.gameObject);
            GameManager.GM.Missile(this);
        }

        if (other.gameObject.layer == LayerMask.NameToLayer("Bullet"))
        {
            Destroy(this.gameObject);
            GameManager.GM.Missile(this);
        }
    }
}