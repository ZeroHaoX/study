using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MonsterActive : MonoBehaviour {
    public GameObject[] monster;
    public GameObject Monster;
    private static MonsterActive instant;
    public static MonsterActive Instant
    {
        get
        {
            return instant;
        }
    }

    void Awake()
    {
        instant= this;
    }

    void Start()
    {
        foreach(GameObject a in monster)
        {
            a.SetActive(false);
            a.GetComponent<BoxCollider>().enabled = false;
        }
        StartCoroutine("Alivetime");
    }

    private void Monsteractive()
    {
        int index = Random.Range(0, monster.Length);
        Monster = monster[index];
        Monster.SetActive(true);
        Monster.GetComponent<BoxCollider>().enabled = true;
        StartCoroutine("Detime");
    }

    private void Monsterdelete()
    {
        if(Monster!=null)
        {
            Monster.SetActive(false);
            Monster.GetComponent<BoxCollider>().enabled = false;
            Monster = null;
            StartCoroutine("Alivetime");
        }
    }

    IEnumerator Alivetime()
    {
        yield return new WaitForSeconds(Random.Range(0, 4));
        Monsteractive();
    }

    IEnumerator Detime()
    {
        yield return new WaitForSeconds(Random.Range(3, 8));
        Monsterdelete();
    }

    public void Updatemonster()
    {
        StopAllCoroutines();
        if(Monster!=null)
        {
            Monster.SetActive(false);
            Monster = null;
        }
        StartCoroutine("Alivetime");
    }
}
