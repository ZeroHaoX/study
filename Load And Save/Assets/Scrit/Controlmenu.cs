using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Controlmenu : MonoBehaviour {
    public GameObject Memu;
    public bool ispause;
    public GameObject[] Target;
    public Toggle Bgmusic;
    private bool ismusic;
    public AudioSource Backgroundmusic;
    

    private static Controlmenu instant;
    public static Controlmenu Instant
    {
        get
        {
            return instant;
        }
    }

    void Awake()
    {
        instant = this;
        Memu.SetActive(false);
        ispause = true;
        pause();
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            pause();
        }
        bgmusic();
    }

    public void pause()
    {
        if (ispause == true)
        {
            Memu.SetActive(true);
            Time.timeScale = 0;
            ispause = false;
            Cursor.visible = true;
        }
        else
        {
            Time.timeScale = 1;
            ispause = true;
            Memu.SetActive(false);
            Cursor.visible = false;
        }
    }

    public void continuegame()
    {
        Time.timeScale = 1;
        Memu.SetActive(false);
        Cursor.visible = false;
        ispause = true;
    }

    public void newgame()
    {
        UImanager.Instant.scores = 0;
        UImanager.Instant.shoots = 0;
        foreach (GameObject a in Target)
        {
            a.GetComponent<MonsterActive>().Updatemonster();
        }
        pause();
    }

    public void quitgame()
    {
        Application.Quit();
    }

    public void bgmusic()
    {
        if (Bgmusic.isOn == true)
        {
            ismusic = true;
            Backgroundmusic.enabled = true;
        }
        else
        {
            ismusic = false;
            Backgroundmusic.enabled = false;
        }
    }

    public void savegame()
    {

    }
}
