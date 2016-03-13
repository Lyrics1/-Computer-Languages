


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265359f

float sx, sy;

typedef float Mat[4][4];
typedef float Vec[4];

void scale(Mat* m, float s) {
    Mat temp = { {s,0,0,0}, {0,s,0,0 }, { 0,0,s,0 }, { 0,0,0,1 } };
    memcpy(m, &temp, sizeof(Mat));
}

void rotateY(Mat* m, float t) {
    float c = cosf(t), s = sinf(t);
    Mat temp = { {c,0,s,0}, {0,1,0,0}, {-s,0,c,0}, {0,0,0,1} };
    memcpy(m, &temp, sizeof(Mat));
}

void rotateZ(Mat* m, float t) {
    float c = cosf(t), s = sinf(t);
    Mat temp = { {c,-s,0,0}, {s,c,0,0}, {0,0,1,0}, {0,0,0,1} };
    memcpy(m, &temp, sizeof(Mat));
}

void translate(Mat* m, float x, float y, float z) {
    Mat temp = { {1,0,0,x}, {0,1,0,y}, {0,0,1,z}, {0,0,0,1} };
    memcpy(m, &temp, sizeof(Mat));
}

void mul(Mat* m, Mat a, Mat b) {
    Mat temp;
    
	for (int j = 0; j < 4; j++)
        for (int i = 0; i < 4; i++) {
            temp[j][i] = 0.0f;
            for (int k = 0; k < 4; k++)
                temp[j][i] += a[j][k] * b[k][i];
        }
    memcpy(m, &temp, sizeof(Mat));    
}

void transformPosition(Vec* r, Mat m, Vec v) {
    Vec temp = { 0, 0, 0, 0 };
    for (int j = 0; j < 4; j++)
        for (int i = 0; i < 4; i++)
            temp[j] += m[j][i] * v[i];
    memcpy(r, &temp, sizeof(Vec));    
}

float transformLength(Mat m, float r) {
    return sqrtf(m[0][0] * m[0][0] + m[0][1] * m[0][1] + m[0][2] * m[0][2]) * r;
}

float sphere(Vec c, float r) {
    float dx = c[0] - sx, dy = c[1] - sy;
    float a = dx * dx + dy * dy;
    return a < r * r ? sqrtf(r * r - a) + c[2] : -1.0f;
}

float opUnion(float z1, float z2) {
    return z1 > z2 ? z1 : z2;
}

float f(Mat m, int n) {
    float z = -1.0f;
    for (float r = 0.0f; r < 0.8f; r += 0.02f) {
        Vec v = { 0.0f, r, 0.0f, 1.0f };
        transformPosition(&v, m, v);
        z = opUnion(z, sphere(v, transformLength(m, 0.05f * (0.95f - r))));
    }

    if (n > 0) {
        Mat ry, rz, s, t, m2, m3;
        rotateZ(&rz, 1.8f);

        for (int p = 0; p < 6; p++) {
            rotateY(&ry, p * (2 * PI / 6));
            mul(&m2, ry, rz);
            float ss = 0.45f;
            for (float r = 0.2f; r < 0.8f; r += 0.1f) {
                scale(&s, ss);
                translate(&t, 0.0f, r, 0.0f);
                mul(&m3, s, m2);
                mul(&m3, t, m3);
                mul(&m3, m, m3);
                z = opUnion(z, f(m3, n - 1));
                ss *= 0.8f;
            }
        }
    }

    return z;
}

float f0(float x, float y, int n) {
    sx = x;
    sy = y;
    Mat m;
    scale(&m, 1.0f);
    return f(m, n);
}

int main(int argc, char* argv[]) {
    int n = argc > 1 ? atoi(argv[1]) : 3;
    float zoom = argc > 2 ? atof(argv[2]) : 1.0f;
    for (float y = 0.8f; y > -0.0f; y -= 0.02f / zoom, putchar('\n'))
        for (float x = -0.35f; x < 0.35f; x += 0.01f / zoom) {
            float z = f0(x, y, n);
            if (z > -1.0f) {
                float nz = 0.001f;
                float nx = f0(x + nz, y, n) - z;
                float ny = f0(x, y + nz, n) - z;
                float nd = sqrtf(nx * nx + ny * ny + nz * nz);
                float d = (nx - ny + nz) / sqrtf(3) / nd;
                d = d > 0.0f ? d : 0.0f;
                // d = d < 1.0f ? d : 1.0f;
                putchar(".-:=+*#%@@"[(int)(d * 9.0f)]);
            }
            else
                putchar(' ');
        }
}
