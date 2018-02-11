using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class foodmaker : MonoBehaviour {
    private static foodmaker instant;
    public static foodmaker Instant
    {
        get
        {
            return instant;
        }
    }
    public int xlimit = 40;
    public int ylimit = 22;
    public Sprite[] foodsprite;
    public GameObject food;
    private Transform foodholder;
    public GameObject daojv;
  

    void Awake()
    {
        instant = this;
    }

    void Start()
    {
        foodholder = GameObject.Find("foodholder").transform;
        makefood(false);
    }

    public void makefood(bool question)
    {
        int index = Random.Range(0, foodsprite.Length);
        GameObject foodsaker = Instantiate(food);
        foodsaker.GetComponent<Image>().sprite = foodsprite[index];
        foodsaker.transform.SetParent(foodholder, false);
        int x = Random.Range(-480, 630);
        int y = Random.Range(-350, 350);
        foodsaker.transform.localPosition = new Vector3(x, y, 0);

        if(question==true)
        {
            GameObject daojvsaker = Instantiate(daojv);
            daojvsaker.transform.SetParent(foodholder, false);
            int t = Random.Range(-480, 630);
            int r = Random.Range(-350, 350);
            foodsaker.transform.localPosition = new Vector3(t, r, 0);
        }
    }

}
