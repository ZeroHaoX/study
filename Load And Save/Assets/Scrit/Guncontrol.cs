using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Guncontrol : MonoBehaviour {
    private float gunXmax = 60;
    private float gunXmin = 0;
    private float gunYmax = 120;
    private float gunYmin = 0;

    public GameObject Bullet;
    public Transform BulletGo;

    private AudioSource fire;

    void Start()
    {
        fire = gameObject.GetComponent<AudioSource>();
    }

   private void Update()
    {
        float xmouse = Input.mousePosition.x / Screen.width;
        float ymouse = Input.mousePosition.y / Screen.height;
        float xposition = -Mathf.Clamp(ymouse * gunXmax, gunXmin, gunXmax)+15;
        float yposition = Mathf.Clamp(xmouse*gunYmax, gunYmin, gunYmax)-60;
        transform.eulerAngles= new Vector3(xposition, yposition, 0);
        if (Controlmenu.Instant.ispause == true)
        {
            creatbullet();
        }
    }

    void creatbullet()
    {
        if (Input.GetMouseButtonDown(0))
        {
            GameObject bullet = GameObject.Instantiate(Bullet, BulletGo.position, Quaternion.identity);
            bullet.GetComponent<Rigidbody>().AddForce(transform.forward*5000);
            gameObject.GetComponent<Animation>().Play();
            UImanager.Instant.shooter();
            fire.Play();
        }
    }
}
