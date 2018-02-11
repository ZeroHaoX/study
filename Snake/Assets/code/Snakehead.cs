using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using UnityEngine.UI;

public class Snakehead : MonoBehaviour {
    private static Snakehead instant;
    public static Snakehead Instant
    {
        get
        {
            return instant;
        }
    }
    public int step;
    public float sudu = 0.3f;
    public float speeds = 0.1f;
    private int x;
    private int y;
    private Vector3 headpos;

    public List<Transform> bodylist = new List<Transform>();
    public GameObject bodyset;
    private Transform canvas;
    public Sprite[] bodysprite = new Sprite[2];

    private bool isdie = false;
    public GameObject Dieeffect;
    public GameObject diewindow;

    public AudioClip eat;
    public AudioClip sdie;

    void Awake()
    {
        instant = this;
        gameObject.GetComponent<Image>().sprite = Resources.Load<Sprite>(PlayerPrefs.GetString("sh","sh01"));
        bodysprite[0] = Resources.Load<Sprite>(PlayerPrefs.GetString("sb"));
        bodysprite[1] = Resources.Load<Sprite>(PlayerPrefs.GetString("sb1"));

    }
    void Start()
    {
        gameObject.transform.localRotation = Quaternion.Euler(0, 0, -90);
        x = step;y = 0;
        InvokeRepeating("Move", 0, sudu);
        canvas = GameObject.Find("Canvas").transform;
    }

    void Update()
    {
        lever();
        if (Input.GetKeyDown(KeyCode.Space)&&MainUI.ispause!=true&& isdie == false)
        {
            speed(speeds);
        }
        if(Input.GetKeyUp(KeyCode.Space) && MainUI.ispause != true && isdie == false)
        {
            dong(sudu);
        }
        if(Input.GetKey(KeyCode.W)&&y!=-step && MainUI.ispause != true && isdie == false)
        {
            gameObject.transform.localRotation = Quaternion.Euler(0, 0, 0);
            x = 0;y = step;
        }
        if (Input.GetKey(KeyCode.S)&&y!=step && MainUI.ispause != true && isdie == false)
        {
            gameObject.transform.localRotation = Quaternion.Euler(0, 0, 180);
            x = 0; y = -step;
        }
        if (Input.GetKey(KeyCode.A)&&x!=step && MainUI.ispause != true && isdie == false)
        {
            gameObject.transform.localRotation = Quaternion.Euler(0, 0, 90);
            x = -step; y = 0;
        }
        if (Input.GetKey(KeyCode.D)&&x!=-step && MainUI.ispause != true && isdie == false)
        {
            gameObject.transform.localRotation = Quaternion.Euler(0, 0, -90);
            x = step; y = 0;
        }
    }
    public void Move()
    {
        headpos = gameObject.transform.localPosition;
        gameObject.transform.localPosition = new Vector3(headpos.x + x, headpos.y+y);
        if (bodylist.Count > 0)
        {
            //    bodylist.Last().localPosition = headpos;
            //    bodylist.Insert(0, bodylist.Last());
            //    bodylist.RemoveAt(bodylist.Count - 1);
   
            for (int i = bodylist.Count-1; i >=0; i--)
            {
                if (i == 0)
                    bodylist[i].localPosition = headpos;
                else bodylist[i].localPosition = bodylist[i - 1].localPosition;
            }
        }

    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        int slong = 1;
        int j = Random.Range(0, 100);
        int daojvfen = Random.Range(0, 100);
        bool question = false;
        if(j<=20)
        {
            question = true;
        }
        if(j>20&&j<=30)
        {
            slong = Random.Range(0, 4);
        }
        if (collision.tag == "food")
        {
            Destroy(collision.gameObject);
            foodmaker.Instant.makefood(question); 
            grow();
            GameObject.Find("sprict").GetComponent<MainUI>().updateUI(5, slong);
        }
        else if(collision.tag=="daojv")
        {
            Destroy(collision.gameObject);
            if (slong > 0)
            {
                for (int i = 1; i <= slong; i++)
                    grow();
            }
            GameObject.Find("sprict").GetComponent<MainUI>().updateUI(daojvfen, slong);
        }
        else if(PlayerPrefs.GetInt("border")==1)
        {
            switch (collision.name)
            {
                case "up":
                    { transform.localPosition = new Vector3(headpos.x, -345, 0); break; }
                case "down":
                    { transform.localPosition = new Vector3(headpos.x, 345, 0); break; }
                case "left":
                    { transform.localPosition = new Vector3(625, headpos.y, 0); break; }
                case "right":
                    { transform.localPosition = new Vector3(-470, headpos.y, 0); break; }
            }
        }
        else if(PlayerPrefs.GetInt("border") == 0)
        {
            if(collision.tag=="wall")
            {
                Die();
            }
        }
        if(collision.tag=="body")
        {
            Die();
        }
    }

    void grow()
    {
        AudioSource.PlayClipAtPoint(eat, Vector3.zero);
        int index = (bodylist.Count % 2 == 0) ? 0 : 1;
        bodyset.GetComponent<Image>().sprite = bodysprite[index];
        GameObject bodysaker = Instantiate(bodyset, new Vector3(2000, 2000, 0), Quaternion.identity);
        bodysaker.transform.SetParent(canvas, false);
        bodylist.Add(bodysaker.transform);
    }

    void Die()
    {
        AudioSource.PlayClipAtPoint(sdie, Vector3.zero);
        CancelInvoke();
        isdie = true;
        Instantiate(Dieeffect);
        PlayerPrefs.SetInt("lastl", MainUI.Instant.length);
        PlayerPrefs.SetInt("lasts", MainUI.Instant.score);
        if (PlayerPrefs.GetInt("bestl",0) < MainUI.Instant.score)
        {
            PlayerPrefs.SetInt("bestl", MainUI.Instant.length);
            PlayerPrefs.SetInt("bests", MainUI.Instant.score);
        }
        StartCoroutine(Gameover(1.5f));
    }

    IEnumerator Gameover(float t)
    {
        yield return new WaitForSeconds(t);
        GameObject Diewindow = Instantiate(diewindow, new Vector3(86, 6, 0), Quaternion.identity);
        Diewindow.transform.SetParent(canvas, false);
    }

    public void speed(float speeds)
    {
        CancelInvoke();
        InvokeRepeating("Move", 0, speeds);
    }

    public void dong(float sudu)
    {
        CancelInvoke();
        InvokeRepeating("Move", 0, sudu);
    }

    public void lever()
    {
        if(MainUI.Instant.score>=800)
        {
            speeds = 0.05f;
            sudu = 0.1f;
        }
    }
}
