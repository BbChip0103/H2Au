using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FlyMath : MonoBehaviour {

	int cnt = 0, cnt_limit = 120;
	int i;
	float height, speed = 0.01f;

	Vector3 move_vector = new Vector3 (0.0f, 1f, 0.0f);
	Vector3 move_vector2 = new Vector3 (-0.7f, 0.0f, 0.0f);

	// Use this for initialization
	void Start () {
		StartCoroutine ("UnityFly");
		height = cnt_limit / 4;
	}
	
	// Update is called once per frame
	void Update () {

	}

	IEnumerator UnityFly(){

		transform.position = move_vector * (1 - (Mathf.Cos(Mathf.PI * cnt * 2 / cnt_limit) / 2.0f + 0.5f)) * height * speed + move_vector2 ;
		if (cnt >= cnt_limit - 2) {
			cnt = 0;
		}
		else{
			cnt+=2;
		}

		yield return new WaitForSeconds(0.01f);

		StartCoroutine ("UnityFly");
	}
}
