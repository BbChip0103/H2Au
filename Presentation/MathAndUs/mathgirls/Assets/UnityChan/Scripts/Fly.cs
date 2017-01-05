using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Fly : MonoBehaviour {

	float height = 0.5f, speed = 0.01f;
	int sw = 0, cnt = 0, cnt_limit = 60;
	int i;

	Vector3 move_vector_up = new Vector3 (0.0f, 1f, 0.0f);
	Vector3 move_vector_down = new Vector3 (0.0f, -1f, 0.0f);
	Vector3 move_vector_location = new Vector3 (0.7f, 0.0f, 0.0f);

	// Use this for initialization
	void Start () {
		StartCoroutine ("UnityFly");

	}

	// Update is called once per frame
	void Update () {

	}

	IEnumerator UnityFly(){
		if (sw == 0) {
			transform.position = move_vector_up * height * speed * cnt;
			transform.position += move_vector_location;
			if (cnt >= cnt_limit - 2) {
				sw = 1;
				cnt = 0;
			} else {
				cnt+=2;
			}
		} else {
			transform.position = move_vector_down * height * speed * cnt;
			transform.position += move_vector_up * cnt_limit * height * speed;
			transform.position += move_vector_location;
			if (cnt >= cnt_limit - 2) {
				sw = 0;
				cnt = 0;
			} else {
				cnt+=2;
			}
		}

		yield return new WaitForSeconds(0.01f);

		StartCoroutine ("UnityFly");
	}
}
