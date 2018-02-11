using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Monstermanager : MonoBehaviour {
    private Animation monsterid;
    public AnimationClip die;
    public AnimationClip isdie;

    private AudioSource kick;

    public void Awake()
    {
        monsterid = gameObject.GetComponent<Animation>();
        kick = gameObject.GetComponent<AudioSource>();
    }

    private void OnCollisionEnter(Collision collision)
    {
        if(collision.collider.tag=="bullet")
        {
            Destroy(collision.collider.gameObject);
            monsterid.clip = die;
            monsterid.Play();
            UImanager.Instant.scorer();
            kick.Play();
            gameObject.GetComponent<BoxCollider>().enabled = false;
            StartCoroutine("Newmonster");
        }
    } 

    private void OnDisable()
    {
        monsterid.clip = isdie;
        gameObject.GetComponent<BoxCollider>().enabled = true;
    }

    IEnumerator Newmonster()
    {
        yield return new WaitForSeconds(1);
        MonsterActive.Instant.Updatemonster();
    }
}
