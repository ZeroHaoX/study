using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class MainUI : MonoBehaviour {
    private static MainUI instant;
    public static MainUI Instant
    {
        get
        {
            return instant;
        }
    }
    public int score = 0;
    public int length = 0;
    public Text scoretext;
    public Text lengthtext;
    public Text lever;
    public Image beijing;
    private Color tempcolor;
    private Color wallcolor;
    public Image pausebutton;
    public Sprite[] buttonsprite;
    public static bool ispause=false;
    public GameObject bg;


    void Awake()
    {
        instant = this;
    }

    void Start()
    {
        if (PlayerPrefs.GetInt("border") == 1)
        {
            foreach (Transform t in bg.transform)
            {
                ColorUtility.TryParseHtmlString("#7CFF82FF", out tempcolor);
                t.GetComponent<Image>().color = tempcolor;
            }
        }
    }
    
    public void updateUI(int fen,int chang)
    {
        score += fen;
        length += chang;
        scoretext.text = "得 分 :\n" + score;
        lengthtext.text = "长 度 :\n" + length;
        switch(score/100)
        {
            case 0:
            case 3:
                {
                    ColorUtility.TryParseHtmlString("#CCEEFFFF", out tempcolor);
                    beijing.color = tempcolor;
                    lever.text = "阶 段 : 1";
                    break;
                }
            case 5:
                {
                    ColorUtility.TryParseHtmlString("#CCFFDBFF", out tempcolor);
                    beijing.color = tempcolor;
                    lever.text = "阶 段 : 2";
                    break;
                }
            case 8:
                {
                    ColorUtility.TryParseHtmlString("#EBFFCCFF", out tempcolor);
                    beijing.color = tempcolor;
                    lever.text = "阶 段 : 3";
                    break;
                }
            case 10:
                {
                    ColorUtility.TryParseHtmlString("#FFF3CCFF", out tempcolor);
                    beijing.color = tempcolor;
                    lever.text = "阶 段 : 4";
                    break;
                }
            case 15:
                {
                    ColorUtility.TryParseHtmlString("#FFDACCFF", out tempcolor);
                    beijing.color = tempcolor;
                    lever.text = "阶 段 : 5";
                    break;
                }
        }
    }
	
    public void pause()
    {
        ispause = !ispause;
        if(ispause==true)
        {
            Time.timeScale = 0;
            pausebutton.sprite = buttonsprite[1];
        }
        else
        {
            Time.timeScale = 1;
            pausebutton.sprite= buttonsprite[0];
        }
    }

    public void home()
    {
        UnityEngine.SceneManagement.SceneManager.LoadScene(0);
    }

    public void began()
    {
        UnityEngine.SceneManagement.SceneManager.LoadScene(1);
    }
}
